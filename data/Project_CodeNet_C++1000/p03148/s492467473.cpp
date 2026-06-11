#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<pair<long long int, int>> sushi(n);
    for(int i=0; i<n; i++){
        cin >> sushi[i].second >> sushi[i].first;
    }
    sort(sushi.begin(),sushi.end());
    reverse(sushi.begin(),sushi.end());

    long long int point = 0;
    vector<int> var(n);
    vector<pair<long long int, int>> multi;
    for(int i=0; i<k; i++){
        point += sushi[i].first;
        var[sushi[i].second - 1] += 1;
        multi.push_back(sushi[i]);// since sorted, most delicious ones are safely excluded
    }
    sort(multi.begin(), multi.end());

    long long int v = 0;
    for(int i=0; i<n; i++){
        if(var[i] >= 1) v += 1;
    }
    point += v * v;

    long long int ans = point;
    long long int test = point;
    int rec = 0;
    for(int i=k; i<n; i++){
        if(v == k) break;
        if(var[sushi[i].second - 1] >= 1) continue;

        // else
        //cout << i << " ";
        test += sushi[i].first + (v+1) * (v+1) - v * v;
		var[sushi[i].second - 1] += 1;
        while(1){
            if(rec == multi.size()) break;
            else if(var[multi[rec].second - 1] == 1){
                rec += 1;
            }
            else{
                test -= multi[rec].first;
                var[multi[rec].second - 1] -= 1;
                rec += 1;
                v += 1;
                break;
            }
        }
        ans = max(ans, test);
        //cout << test << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
