#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    
    if(a>b)swap(a,b);
    
    int count = 0;
    
    for(int i=a; i>0; i--){
        if(a%i==0 && b%i==0)
            count++;
        
        if(count==k){
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}