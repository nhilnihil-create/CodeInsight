#include <iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;



int main() {
    int n,m;
    cin>>n>>m;
    vector<int>l(m);
    vector<int>r(m);
    rep(i,m)cin>>l[i]>>r[i];
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    int pass;
    if(r[0]<l[m-1])pass=0;
    else pass =r[0]-l[m-1]+1;
    cout<<pass<<endl;

    return 0;
}