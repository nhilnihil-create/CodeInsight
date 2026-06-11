#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> vec1;
    vector<int> vec2;
    for (int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        vec1.push_back(t);
    }
    for (int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        vec2.push_back(t);
    }

    sort(vec1.begin(), vec1.end());
    reverse(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());


    bool war = true;
    for (int i = vec1[0] + 1; i <= vec2[0]; i ++) {
        if (i > x && i <= y){
            war = false;
            break;
        }
    }

    if (war)
        cout << "War";
    else
        cout << "No War";

    return 0;
}