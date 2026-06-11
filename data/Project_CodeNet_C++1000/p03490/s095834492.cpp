#include <bits/stdc++.h>
#define F first
#define S second
#define SZ size()

using namespace std;
typedef long long ll;

int in(){int a; scanf("%d", &a); return a;}
ll inll(){ll a; scanf("%lld", &a); return a;}

//--------------------------------------------------

const int MAX = 8e3 + 5;
const int INF = 0x3f3f3f3f;

string s;
int X, Y;
vector <int> xsteps, ysteps;


int memx[MAX][MAX];

bool dpx(int i, int curX) {

    if(i == xsteps.SZ) return curX == X;
    int &res = memx[i][curX];
    if(res != -1) return res;
    res = 0;
    res = dpx(i+1, curX + xsteps[i]) || dpx(i+1, curX - xsteps[i]);
    return res;
}

int memy[MAX][MAX];

bool dpy(int i, int curY) {

    if(i == ysteps.SZ) return curY == Y;
    int &res = memy[i][curY];
    if(res != -1) return res;
    res = 0;
    res = dpy(i+1, curY + ysteps[i]) || dpy(i+1, curY - ysteps[i]);
    return res;
}


int main(){

    memset(memx, -1, sizeof memx);
    memset(memy, -1, sizeof memy);

    cin >> s;
    s = s + 'T';

    X = in(), Y = in();

    int steps = 0;
    int turns = 0;
    int xstart = 0;

    for(int i=0; i<s.SZ; i++){

        if(s[i] == 'F') steps++;

        else {

            if(turns == 0) {
                xstart = steps;
            }

            else if(steps > 0) {
                if(turns % 2 == 0) xsteps.push_back(steps);
                else ysteps.push_back(steps);
            }

            turns++;
            steps = 0;
        }
    }

    if(dpx(0, xstart) && dpy(0, 0)) printf("Yes\n");
    else printf("No\n");

}

