#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int X, Y;
bool D[20202];
char str[10101];
vector<int> XM, YM, V;

int main(){
    scanf("%s", str+1);
    scanf("%d %d", &X, &Y);
    int cnt=0, xy=1;
    for (int i=1; str[i]; i++){
        if (str[i] == 'F') cnt++;
        else{
            if (xy == 1) XM.push_back(cnt);
            else YM.push_back(cnt);
            cnt=0, xy = -xy;
        }
    }
    if (xy == 1) XM.push_back(cnt);
    else YM.push_back(cnt);

    int l = XM[0]+10000, r = XM[0]+10000;
    D[XM[0]+10000] = true;
    for (int i=1; i<(int)XM.size(); i++){
        V.clear();
        for (int j=l; j<=r; j++) {
            if (D[j]) V.push_back(j);
            D[j] = false;
        }
        l = 20000, r = 0;
        for (int t : V){
            l = min(l, t-XM[i]);
            r = max(r, t+XM[i]);
            D[t-XM[i]] = D[t+XM[i]] = true;
        }
    }
    if (!D[X+10000]){
        puts("No");
        return 0;
    }

    memset(D, false, sizeof D);
    l = 10000, r = 10000;
    D[10000] = true;
    for (int i=0; i<(int)YM.size(); i++){
        V.clear();
        for (int j=l; j<=r; j++) {
            if (D[j]) V.push_back(j);
            D[j] = false;
        }
        l = 20000, r = 0;
        for (int t : V){
            l = min(l, t-YM[i]);
            r = max(r, t+YM[i]);
            D[t-YM[i]] = D[t+YM[i]] = true;
        }
    }
    if (!D[Y+10000]){
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}
