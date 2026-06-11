#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int n,m;
	cin>>n>>m;
	vector<ll>x(n),y(n),z(n);
	for(int i=0;i<n;i++)cin>>x[i]>>y[i]>>z[i];
    vector<pair<ll, ll>> p1(n),p2(n),p3(n),p4(n),p5(n),p6(n),p7(n),p8(n);
    for(int i=0;i<n;i++) p1[i] = make_pair(x[i] + y[i] + z[i], i);
    for(int i=0;i<n;i++) p2[i] = make_pair(-x[i] + y[i] + z[i], i);
    for(int i=0;i<n;i++) p3[i] = make_pair(x[i] - y[i] + z[i], i);
    for(int i=0;i<n;i++) p4[i] = make_pair(x[i] + y[i] - z[i], i);
    for(int i=0;i<n;i++) p5[i] = make_pair(-x[i] - y[i] + z[i], i);
    for(int i=0;i<n;i++) p6[i] = make_pair(x[i] - y[i] - z[i], i);
    for(int i=0;i<n;i++) p7[i] = make_pair(-x[i] + y[i] - z[i], i);
    for(int i=0;i<n;i++) p8[i] = make_pair(-x[i] - y[i] - z[i], i);
    
    sort(p1.begin(),p1.end());
    reverse(p1.begin(),p1.end());
    sort(p2.begin(),p2.end());
    reverse(p2.begin(),p2.end());
    sort(p3.begin(),p3.end());
    reverse(p3.begin(),p3.end());
    sort(p4.begin(),p4.end());
    reverse(p4.begin(),p4.end());
    sort(p5.begin(),p5.end());
    reverse(p5.begin(),p5.end());
    sort(p6.begin(),p6.end());
    reverse(p6.begin(),p6.end());
    sort(p7.begin(),p7.end());
    reverse(p7.begin(),p7.end());
    sort(p8.begin(),p8.end());
    reverse(p8.begin(),p8.end());
 
 
    vector<vector<ll>> ans(8,vector<ll>(3));
    for(int i=0;i<m;i++)
    {
        vector<ll>ind(8);
        ind[0] = p1[i].second;
        ind[1] = p2[i].second;
        ind[2] = p3[i].second;
        ind[3] = p4[i].second;
        ind[4] = p5[i].second;
        ind[5] = p6[i].second;
        ind[6] = p7[i].second;
        ind[7] = p8[i].second;
        for(int j=0;j<8;j++)
        {
            ans[j][0] += x[ind[j]];
            ans[j][1] += y[ind[j]];
            ans[j][2] += z[ind[j]];
        }
    }
    vector<ll>res(8);
    for(int i=0;i<8;i++)
    {
        res[i] = abs(ans[i][0]) + abs(ans[i][1]) + abs(ans[i][2]);
    }
    sort(res.begin(),res.end());
    cout<<res[7]<<"\n";

}
	
