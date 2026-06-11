#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    const int MX = 55555;
    vector<int> p;
    bool isp[MX+1];
    fill(isp, isp+MX+1, true);
    for(int i=2; i<=MX; i++){
        if(!isp[i]) continue;
        p.push_back(i);
        int t = i+i;
        while(t <= MX){
            isp[t] = false;
            t += i;
        }
    }

    int cnt = 0;
    for(int q: p){
        if(q % 5 == 1){
            cout << q << " ";
            cnt++;
        }
        if(cnt == N) break;
    }

    cout << endl;

    return 0;
}
