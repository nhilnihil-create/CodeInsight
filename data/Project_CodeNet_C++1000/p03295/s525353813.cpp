 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;

 int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> bridge;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        pair<int,int> pr = make_pair(b,a);
        bridge.push_back(pr);
    }
    sort(bridge.begin(),bridge.end());
    int cnt = 0;
    int endtime = 0;
    for(int i=0;i<m;i++){
        if(bridge[i].second >= endtime){
            endtime = bridge[i].first;
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
 }