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
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> vec;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int pos=lower_bound(vec.begin(),vec.end(),k)-vec.begin();
    cout<<min(pos,m-pos);
}

