# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <cstring>
# include <stdio.h>
# include <map>
# include <queue>

# define ll long long
# define pii pair<int,int>
# define FOR(a,b) for(int a=1; a<=b; a++)
# define REP(a,b) for(int a=0; a<b; a++)
# define FORU(a,b,c) for(int a=b; a<=c; a++)
# define FORD(a,b,c) for(int a=b; a>=c; a--)

using namespace std;

ll posCW[100005], posCCW[100005], suff[100005], pref[100005], dp1[100005], dp2[100005];
ll N, L;

//pref[x] : calories get to eat x-th sushi from counterclockwise direction (1 .. x)
//suff[x] : calories get to eat x-th sushi from clockwise direction (N .. x)
//posCCW : distance to the sushi in counterclockwise direction from starting point
//posCW : distance to the sushi in clockwise direction from starting point

int main(){

    ios :: sync_with_stdio(false);
    cin >> N >> L;
    FOR(i,N){
        cin >> posCCW[i] >> pref[i];
        posCW[i] = L - posCCW[i];
        suff[i] = pref[i];
        pref[i] += pref[i-1];
    }

    FORD(i,N,0){
        suff[i] += suff[i+1];
    }

    FOR(i,N){
        //option 1a : walk counter-lockwise to A, then back to starting point
        dp1[i] = max(dp1[i-1], pref[i] - 2*posCCW[i]);

        //option 2a : walk counter clockwise to A
        dp2[i] = max(dp2[i-1], pref[i] - posCCW[i]);
    }

    ll ans = 0;
    FOR(i,N+1){
        ans = max(ans, max(
            //option 1b : after option 1a, walk clockwise from starting point to B
            dp1[i-1] + suff[i] - posCW[i],

            //option 2b : before option 2a, walk clockwise from starting point to B, then back to starting point
            dp2[i-1] + suff[i] - 2*posCW[i]
        ));
    }

    cout << ans << endl;
    return 0;
}