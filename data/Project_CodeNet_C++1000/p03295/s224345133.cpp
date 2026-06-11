#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int main(void){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> war;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        war.push_back(make_pair(a,b));
    }
    sort(war.begin(),war.end());
    int l,r;
    int ans=1;
    l = war[0].first;
    r = war[0].second;
    for(int i=1;i<war.size();i++){
        if(war[i].first >= r){
            ans++;
            l = war[i].first;
            r = war[i].second;
        }
        else{
            if(war[i].second < r){
                r = war[i].second;
            }
        }
    }
    cout << ans << endl;
}
