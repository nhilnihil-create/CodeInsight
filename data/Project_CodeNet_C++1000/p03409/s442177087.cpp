#include <bits/stdc++.h>
#include <queue>
using namespace std;
using P = pair<int,int>;

int main() {
    int n; cin >> n;
    vector<P> red(n);
    vector<P> blue(n);
    for(int i=0; i<n; i++){
        cin >> red[i].second;
        cin >> red[i].first;
    }
    for(int i=0; i<n; i++){
        cin >> blue[i].first;
        cin >> blue[i].second;
    }
    //blueはx座標で昇順(blueは(x,y))
    sort(blue.begin(),blue.end());
    //redはy座標で降順(redは(y,x))
    sort(red.begin(),red.end(),greater<P>());
    //redをカウントしたかメモ
    vector<bool> used(n,false);

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(blue[i].first > red[j].second && blue[i].second > red[j].first && !used[j]){
                used[j] = true;
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}