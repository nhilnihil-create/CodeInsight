#include <bits/stdc++.h>
using namespace std;
// 2D Plane 2N Points
typedef pair<int, int> P;

bool pairCompare(P a, P b){
    // if(a.first == b.first){
    //     return a.second < b.second;
    // }else{
    //     return a.first > b.first;
    // }
    return a.second < b.second;
}

int main(){
    int N;
    cin >> N;
    vector<P> a(N), b(N);

    for(int i = 0; i < N; ++i){
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 0; i < N; ++i){
        cin >> b[i].first >> b[i].second;
    }
    // 降順
    sort(a.begin(), a.end(), pairCompare);
    sort(b.rbegin(), b.rend());
    // for(int i = 0; i < N; ++i){
    //     cout << a[i].first << " " << a[i].second << endl;
    // }
    // cout << endl;
    int pair = 0;
    while(b.size() > 0){
        P blue = b.back();
        b.pop_back();
        //cout << blue.first << " " << blue.second << endl;
        for(int i = a.size() - 1; i >= 0; --i){  
            if(a[i].first < blue.first && a[i].second < blue.second){
                //cout << a[i].first << " " << a[i].second << endl;
                a.erase(a.begin() + i);
                pair++;
                break;
            }
        }        
    }
    cout << pair << endl;
    return 0;
}

