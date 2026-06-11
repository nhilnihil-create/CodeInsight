#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N), d(N);
    vector<pair<int, int>> p_r(N), p_b(N);
    rep(i, 0, N){
        cin >> a.at(i) >> b.at(i);
        p_r.at(i) = make_pair(a.at(i), b.at(i));
    }
    rep(i, 0, N){
        cin >> c.at(i) >> d.at(i);
        p_b.at(i) = make_pair(c.at(i), d.at(i));
    }
    sort(all(p_r));
    sort(all(p_b));
    set<int> foot;
    int count = 0;
    rep(i, 0, N){
        int bx = p_b.at(i).first;
        int by = p_b.at(i).second;
        int maxy = -300;
        int numy;
        //cout << "B " << bx << " " << by << endl;
        for (int j = 0; j < N; j++){
            if (!foot.count(j)){
                int rx = p_r.at(j).first;
                int ry = p_r.at(j).second;
                //cout << "R " << rx << " " << ry << endl;
                if (rx < bx){
                    if (ry < by){
                        if (maxy < ry){
                            maxy = ry;
                            numy = j;
                            //cout << " OK " << endl;
                        }
                    }
                }
            }
            if (j == N - 1){
                if (maxy != -300){
                    foot.insert(numy);
                    count++;
                }
            }
        }
        
    }
    cout << count << endl;
}