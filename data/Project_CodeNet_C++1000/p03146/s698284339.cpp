#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int f(int n){
    if(n%2 == 0)
        return n/2;
    else
        return 3*n + 1;
}

int main(){
    int s;
    cin >> s;

    int m=0; 
    int x=s;
    set<int> a;
    while(a.count(x) == 0){
        a.insert(x);
        x = f(x); m++;
    }
    cout << (a.size()+1) << endl;
    return 0;
}