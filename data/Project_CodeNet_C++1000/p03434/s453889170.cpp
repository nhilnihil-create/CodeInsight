#include <bits/stdc++.h>
using namespace std;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; i++)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; i--)
#define vi vector<int>
#define vs vector<string>
#define all(x) (x).begin(),(x).end()
int main() {
    int n,alice,bob;
    alice=0;
    bob=0;
    cin>>n;
    vi a(n);
    repp(i,0,n){
        cin>>a[i];
    }
    sort(all(a), greater<int>());
    repp(i,0,n){
        if(i%2){
            bob+=a[i];
        }else{
            alice+=a[i];
        }
    }

    cout<< alice - bob <<endl;
}