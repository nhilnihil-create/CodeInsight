#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num, m;
    cin >> num >> m;

    vector<long long> vec(m);
    vector<long long> vec2(m);
    vector<vector<long long>> data(num);
    for (int i = 0; i < m; i++) {
        cin >> vec.at(i) >> vec2.at(i);
        vec.at(i)--;
    }

    for (int i = 0; i < m; i++) { data.at(vec.at(i)).push_back(vec2.at(i)); }

    for (int i = 0; i < num; i++) {
        sort(data.at(i).begin(), data.at(i).end());
        data.at(i).erase(unique(data.at(i).begin(), data.at(i).end()), data.at(i).end());
    }

    for (int i = 0; i < m; i++) {
        int j = vec.at(i);
        long long id = lower_bound(data.at(j).begin(), data.at(j).end(), vec2.at(i)) - data.at(j).begin();
        cout << setfill('0') << right << setw(6) << vec.at(i)+1;
        cout << setfill('0') << right << setw(6) << id+1 << endl;
    }

    //
}
