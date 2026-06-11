#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ipair;

int main(){
    int n;
    cin >> n;
    priority_queue<int> takahashi;
    ll sum=0;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        takahashi.push(a+b);
        sum-=b;        
    }
    ll t=0;
    int i=0;
    while(!takahashi.empty()){
        int tmp=takahashi.top();takahashi.pop();
        if(i%2==0){
            t+=tmp;
        }
        i++;
    }
    cout << (ll)t+sum << endl;
}