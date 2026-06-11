#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    vector<pair<int,int>> r(n),b(n);
    for(int i=0;i<n;i++){
        int a,c;
        cin >> a >> c;
        r[i] = {a,c};
    }
    for(int i=0;i<n;i++){
        int a,c;
        cin >> a >> c;
        b[i] = {a,c};
    }

    sort(r.begin(),r.end());
    sort(b.begin(),b.end());

    vector<bool> used(n,false);
    int count = 0;
    for(int i=0;i<n;i++){
        int maxy = -1;
        int posr = -1;
        for(int j=0;j<r.size();j++){
            if(r[j].first>=b[i].first) break;
            if(r[j].second>=b[i].second) continue;
            if(used[j]) continue;
            
            if(maxy<r[j].second){
                maxy = r[j].second;
                posr = j;
            }
        }

        if(posr==-1) continue;
        else{
            count++;
            used[posr] = true;
        }
    }

    cout << count << endl;
}