#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<pair<int, int>> red, blue;

    for(int i=0; i<2*N; i++){
        int x, y; cin >> x >> y;
        if(i<N) red.push_back(make_pair(x, y));
        else blue.push_back(make_pair(x,y));
    }
    sort(red.begin(),red.end());
    sort(blue.begin(),blue.end());

    int count = 0;
    //for(auto i : red) cout << i.first << endl;
    for(int i=0; i<N; i++){
        auto r = red[N-1-i];
        //cout << " r : " << r.first << " " << r.second << endl;
        int minimum_y = INT_MAX;
        int memo;
        for(int i=0; i<blue.size(); i++){
            if(blue[i].first > r.first && blue[i].second > r.second && blue[i].second<minimum_y){
                minimum_y = blue[i].second;
                memo = i;
                //cout << blue[i].first << " " << minimum_y << endl;
            }
        }
        if(minimum_y!=INT_MAX){
            blue.erase(blue.begin()+memo);
            count++;
        }
    }
    cout << count << endl;
}
