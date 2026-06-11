#include<bits/stdc++.h>
using namespace std;
bool p(int a){
    if(0 < a && a < 13) return true;
    else return false;
}
int main(){
    double n, k;
    cin >> n >> k;
    double sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        int s = ceil(log2(k/i)) ;
        if(s>-1) sum += pow(0.5,s);
        else sum  += 1;
    }
    cout << fixed << setprecision(20) <<  sum/n << endl;
}