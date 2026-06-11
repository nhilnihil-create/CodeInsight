#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    typedef pair<string, int> store_site;
    priority_queue<store_site, vector<store_site>, greater<store_site>> que_site;
    vector<int> P(N);

    for(int i=0; i<N; i++){
        string s;
        cin >> s >> P[i];
        que_site.push(store_site(s, i));
    }

    typedef pair<int, int> store_point;
    priority_queue<store_point> que;
    string target_name = que_site.top().first;
    while (!que_site.empty()) {
        store_site s = que_site.top();
        string site_name = s.first;
        int index = s.second;
        if(site_name == target_name){
            que.push(store_point(P[index], index));
        }else{
            while(!que.empty()){
                store_point ans = que.top();
                cout << ans.second + 1 << endl;
                que.pop();
            }
            target_name = site_name;
            que.push(store_point(P[index], index));
        }
        que_site.pop();
    }
    while(!que.empty()){
        store_point ans = que.top();
        cout << ans.second + 1 << endl;
        que.pop();
    }

    return 0;    

}