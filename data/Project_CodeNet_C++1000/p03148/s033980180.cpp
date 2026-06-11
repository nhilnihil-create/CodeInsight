#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
    long N, K;
    cin>>N>>K;
    map<int, vector<long> > sushimap;
    vector<int> sushiarr;
    long t, d;
    for(int i=0;i<N;++i){
        cin>>t>>d;
        if(sushimap[t].size()==0)sushiarr.push_back(t);
        sushimap[t].push_back(d);
    }
    for(int i=0;i<sushiarr.size();++i){
        sort(sushimap[sushiarr[i]].begin(), sushimap[sushiarr[i]].end());
    }
    vector<long> diffsushis;
    vector<long> sushis;
    priority_queue<long, vector<long>, greater<long> >eat;
    for(int i=0;i<sushiarr.size();++i){
        diffsushis.push_back(sushimap[sushiarr[i]][sushimap[sushiarr[i]].size()-1]);
        for(int j=0;j<sushimap[sushiarr[i]].size()-1;++j){
            sushis.push_back(sushimap[sushiarr[i]][j]);
        }
    }
    sort(diffsushis.begin(), diffsushis.end());
    sort(sushis.begin(), sushis.end(), greater<long>());
    long ans = 0;
    if(diffsushis.size()>=K){
        for(int i=0;i<K;++i){
            eat.push(diffsushis[diffsushis.size()-1-i]);
            ans += diffsushis[diffsushis.size()-1-i];
        }
        ans += K*K;
        long bonus = K;
        for(int i=0;i<sushis.size();++i){
            if(ans < ans - bonus*bonus - eat.top() + (bonus-1)*(bonus-1) + sushis[i]){
                ans = ans - bonus*bonus - eat.top() + (bonus-1)*(bonus-1) + sushis[i];
                eat.pop();
                eat.push(sushis[i]);
                bonus--;
            }
            else break;
            if(bonus == 1)break;
        }
    }
    else{
        for(int i=0;i<diffsushis.size();++i){
            eat.push(diffsushis[i]);
            ans += diffsushis[i];
        }
        int index = K - diffsushis.size();
        for(int i=0;i<index;++i){
            ans += sushis[i];
        }
        long bonus = diffsushis.size();
        ans += bonus * bonus;
        for(int i=index;i<sushis.size();++i){
            if(ans < ans - bonus*bonus - eat.top() + (bonus-1)*(bonus-1) + sushis[i]){
                ans = ans - bonus*bonus - eat.top() + (bonus-1)*(bonus-1) + sushis[i];
                eat.pop();
                eat.push(sushis[i]);
                bonus--;
            }
            else break;
            if(bonus == 1)break;
        }
    }
    cout<<ans<<endl;
}
