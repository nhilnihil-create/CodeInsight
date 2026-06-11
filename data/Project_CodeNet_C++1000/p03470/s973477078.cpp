#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    vector<int> d(110);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> d.at(i);
    }
    sort(d.begin(), d.end(), greater<int>());
    int ans = N;
    for (int i = 0; i < N; i++)
    {
        if(d.at(i)==d.at(i+1)) {
            ans--;
        }
    }
    cout << ans << endl;
}