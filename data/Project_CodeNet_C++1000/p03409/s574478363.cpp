#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int N;
    cin >> N;
    pair<int, int> red[N], blue[N];
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        red[i] = {b, a};
    }
    for(int i=0; i<N; i++){
        int c, d;
        cin >> c >> d;
        blue[i] = {c, d};
    }
    sort(red, red + N, greater<>() ); sort(blue, blue + N);
    bool r_u[N], b_u[N]; fill(r_u, r_u + N, true); fill(b_u, b_u + N, true);
    int ans = 0;
    for(int j=0; j<N; j++){
        for(int i=0; i<N; i++){
            if(r_u[i] && b_u[j] && blue[j].first > red[i].second && blue[j].second > red[i].first){
                r_u[i] = false;
                b_u[j] = false;
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}