#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int get(int n){
    if(n%2==0)return n/2;
    else return 3*n+1;
}
int main(){
    set<int> s;
    int x;
    cin>>x;
    for(int i=2;;i++){
        s.insert(x);
        x=get(x);
        if(s.count(x)){
            cout<<i;
            return 0;
        }
    }
}

