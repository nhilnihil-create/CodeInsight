#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> a,b;
    for(int i=0;i<n;i++){
        int c,d;
        cin >> c >> d;
        a.push_back(make_pair(d,c));
    }
    for(int i=0;i<n;i++){
        int c,d;
        cin >> c >> d;
        b.push_back(make_pair(c,d));
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> ismatch(n,0);
    int cnt = 0;
    for(int i=0;i<n;i++){//blue
        int c = -1;
        for(int j=0;j<n;j++){//red
            if(ismatch[j]) continue;
            if(a[j].second<b[i].first&&a[j].first<b[i].second){
                c = max(c,j);
            }
        }
        if(c!=-1){
            ismatch[c]=1;
            cnt++;
        }
    }
    cout << cnt << endl;
}
