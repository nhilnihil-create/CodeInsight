#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <iomanip>
#include <queue>
#include <algorithm>
#include<set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>> vws(2*(n-1));
    vector<int> sn(n,0);
    vector<int> vwind(n+1,0);
    // vector<vector<int>> mat(n,vector<int>(n));
    vector<pair<int,int>> mat(2*(n-1));
    vector<long long int> ds(n,-1);
    // vector<int> 
    int u,v;
    long long int w;
    for(int i=0;i<n-1;i++){
        cin >> u >> v >>w;
        u--;v--;
        // mat.at(i)=make_pair(u,v);
        // mat.at(i)=make_pair(v,u);
        sn.at(u)++;
        sn.at(v)++;
        vws.at(2*i) = make_pair(make_pair(u,v),w);
        vws.at(2*i+1) = make_pair(make_pair(v,u),w);
    }
    sort(vws.begin(),vws.end());
    vwind.at(0)=0;
    for(int i=1;i<n;i++){
        vwind.at(i)=vwind.at(i-1)+sn.at(i-1);
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<sn.at(i);j++){
    //         cout << mat.at(i).at(j) << ",";
            
    //     }
    //     cout << endl;
    // }
    queue<int> que;
    int search;
    int dst;
    long long int dnow;
    que.push(0);
    ds.at(0)=0;
    while(!que.empty()){
        search=que.front();
        que.pop();
        dnow=ds.at(search);
        // cout << search << endl;
        for(int i=vwind.at(search);i<vwind.at(search)+sn.at(search);i++){
            dst = vws.at(i).first.second;
            
            if(ds.at(dst)==-1){
                ds.at(dst)=dnow+vws.at(i).second;
                que.push(dst);
                // cout << dst << "," << ds.at(dst) <<endl;
            }
            
        }
    }
    for(int i=0;i<n;i++){
        if(ds.at(i)&1)cout << 1 << endl;
        else cout << 0 << endl;
    }

}
