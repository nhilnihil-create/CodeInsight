#include <iostream>
#include <map>
#define ll long long
using namespace std;
int main(){
    int n, x;
    ll sum=0, cow[200005];
    cin >> n;
    map <ll , int> zesura;
    zesura[0]=1;
    cow[0]=0;
    for(int i=1; i<=n; i++){
        cin >> x;
        cow[i]=x+cow[i-1];
        zesura[cow[i]]++;
        if(zesura[cow[i]]>1){
            sum+=zesura[cow[i]]-1;
        }    
    }
    cout << sum << endl;
    return 0;
}