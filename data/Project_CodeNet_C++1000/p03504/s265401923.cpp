#include <iostream>
#include <vector>
using namespace std;
int const v = 200002;
vector< vector<int> > foo;
int main(void){
    int n, c, ans = 0;
    cin >> n >> c;
    foo.assign(c, vector<int>(v, 0));
    for(int i=0;i<n;i++){
        int s, t, u;
        cin >> s >> t >> u;
        u--;
        foo[u][s*2]++;
        foo[u][t*2]--;
    }
    for(int i=0;i<c;i++){
        for(int j=1;j<v;j++){
            foo[i][j] += foo[i][j-1];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<v;j++){
            if(foo[i][j] == 0 && foo[i][j+1] > 0){
                foo[i][j]++;
            }
        }
    }
    for(int j=0;j<v;j++){
        int cnt = 0;
        for(int i=0;i<c;i++){
            if(foo[i][j] > 0) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
	return 0;
}
