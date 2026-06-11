#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define ull unsigned long long
using namespace std;

const int nmax = 100100;
int N;
ull A,B;
void solve(ull A, ull B);
void read(){
    cin >> N;
    for(int i=0;i < N; ++i){
        cin >> A >> B;
        solve(A, B);
    }
}
ull bs(ull n)
{
    ull L = 1, R =(unsigned long long)2000000000, mid;
    while( (R-L) > 1)
    {
        mid = (R+L) >> 1;
        if(((mid+1)*(mid+1))/4 > n)
            R = mid;
        else
            L = mid;
    }
    return L;
}
void solve(ull A, ull B){
    if(A > B) swap(A,B);
    if(B == 1)
    {
        cout << 0 << endl;
        return;
    }
    ull x = A * B - 1;
    cout << bs(x) - (A==B ? 0:1) << endl;
}

int main(){
    read();
}