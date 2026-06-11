#include <cstdio>
#include <vector>
using namespace std;

char s[11111];
int x, y;
int d1[32006][2], d2[32006][2];
vector<pair<int, int> > v;

int main() {
    scanf("%s", s+1);
    scanf("%d %d", &x, &y);

    int n;
    for (n = 1; s[n]; n++);
    n--;

    s[0] = s[1];
    int cnt = 0;
    int fuck = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[i-1]) {
            cnt++;
        }
        else {
            if (v.size() == 0 && s[i-1] == 'F') {
                fuck = 1;
            }
            v.push_back({ cnt,s[i-1] == 'F'} );
            cnt = 1;
        }
    }
    if (cnt) {
        if (v.size() == 0 && s[n] == 'F') {
            fuck = 1;
        }
        v.push_back({ cnt,s[n] == 'F' });
    }



    int flag = 0;
    vector<int> a, b;
    for (auto it : v) {
        if (it.second == 0) {
            flag = (flag+it.first)%2;
        }
        else {
            if (flag) b.push_back(it.first);
            else a.push_back(it.first);
        }
    }
    


    d1[16000][0] = 1;
    d2[16000][0] = 1;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j <= 32000; j++) {
            int aa = j-a[i] >= 0 ? d1[j-a[i]][i%2] : 0;
            int bb = j+a[i] <= 32000 ? d1[j+a[i]][i%2] : 0;
            if (fuck && i == 0) {
                bb = 0;
            }
            d1[j][(i+1)%2] = (aa | bb);
        }
    }
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j <= 32000; j++) {
            int aa = j-b[i] >= 0 ? d2[j-b[i]][i%2] : 0;
            int bb = j+b[i] <= 32000 ? d2[j+b[i]][i%2] : 0;
            d2[j][(i+1)%2] = (aa | bb);
        }
    }

/*
    for (int it : a) printf("%d ", it);
    puts("");
    for (int it : b) printf("%d ", it);
    puts("");


    for (int i = 7990; i <= 8010; i++) {
        printf("%d ", i);
    }
    puts("");
    for (int i = 7990; i <= 8010; i++) {
        printf("%4d ", d2[i][0]);
    }
    puts("");
    for (int i = 7990; i <= 8010; i++) {
        printf("%4d ", d2[i][1]);
    }

    printf("\n%d %d\n", d1[x+8000][a.size()%2], d2[y+8000][b.size()%2]);
    */

    if (d1[x+16000][a.size()%2] && d2[y+16000][b.size()%2]) {
        puts("Yes");
    }
    else {
        puts("No");
    }

    return 0;
}