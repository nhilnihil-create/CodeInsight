#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,p;
    long long int y;
    cin>>n>>m;
    std::multimap<int, long long int> map;
    std::map<long long int, int> year;
    for (int i=0;i<m;i++) {
        cin>>p>>y;
        map.emplace(p,y);
        year.emplace(y,i+1);
    }
    std::deque<string> ans(100001,"");
    for (int i=1;i<=n;i++) {
        auto p=map.equal_range(i);
        std::deque<long long int> deq;
        for (auto itr=p.first;itr!=p.second;itr++) {
            deq.emplace_back(itr->second);
        }
        sort(deq.begin(),deq.end());
        for (int j=0;j<deq.size();j++) {
            string tmp="";
            if (to_string(i).size()==5) {
                tmp=tmp+"0"+to_string(i);
            } else if (to_string(i).size()==4) {
                tmp=tmp+"00"+to_string(i);
            } else if (to_string(i).size()==3) {
                tmp=tmp+"000"+to_string(i);
            } else if (to_string(i).size()==2) {
                tmp=tmp+"0000"+to_string(i);
            } else if (to_string(i).size()==1) {
                tmp=tmp+"00000"+to_string(i);
            } else {
                tmp=tmp+to_string(i);
            }
            if (to_string(j+1).size()==5) {
                tmp=tmp+"0"+to_string(j+1);
            } else if (to_string(j+1).size()==4) {
                tmp=tmp+"00"+to_string(j+1);
            } else if (to_string(j+1).size()==3) {
                tmp=tmp+"000"+to_string(j+1);
            } else if (to_string(j+1).size()==2) {
                tmp=tmp+"0000"+to_string(j+1);
            } else if (to_string(j+1).size()==1) {
                tmp=tmp+"00000"+to_string(j+1);
            } else {
                tmp=tmp+to_string(j+1);
            }
            ans[year[deq[j]]]=tmp;
        }
    }
    for (int i=0;i<ans.size();i++) {
        if (ans[i]!="") {
            cout<<ans[i]<<endl;
        }
    }
}