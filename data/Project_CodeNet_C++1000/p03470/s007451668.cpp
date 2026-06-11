#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    vector<int> d(N);

    for(int i=0;i<N;i++){
        cin >> d.at(i);
    }

    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());

    int ans=0;

    for(int i=0;i<d.size()-1;i++){
        if(d.at(i)>d.at(i+1)){
            ans++;
        }
    }

    cout << ans+1 << endl;
}