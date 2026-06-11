#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct pos{
    int x;
    int y;
};
int main(){
    int N;
    vector<pair<pos, bool>> R, B;
    cin >> N;
    R.resize(N);
    B.resize(N);

    for (int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        pos p = {a, b};
        R[i] = make_pair(p, false);
    }
    for (int i = 0; i < N; i++)
    {
        int c, d;
        cin >> c >> d;
        pos p = {c, d};
        B[i] = make_pair(p, false);
    }
    sort(B.begin(), B.end(), [](const pair<pos, bool> &m, const pair<pos, bool> &n) { return m.first.x < n.first.x; });
    sort(R.begin(), R.end(), [](const pair<pos, bool> &m, const pair<pos, bool> &n) { return m.first.y > n.first.y; });

    int count = 0;
    for (int i = 0; i < N; i++){
        pos b = B[i].first;
        for (int j = 0; j < N; j++){
            if((R[j].first.y < b.y) && (R[j].first.x < b.x) && !R[j].second){
                count++;
                R[j].second = true;
                break;
            }
        }
    }

    cout << count << endl;
}