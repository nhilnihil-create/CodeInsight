#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
const ll INF = 1000000000000007;

using namespace std;

int main(){
    ll A,B,C,X,Y,res;
    cin >> A >> B >> C >> X >> Y;

    ll iMin = INF;

    //plan1 A,BをそれぞれX,Y枚買う
    iMin = min(iMin, A*X + B*Y);

    //plan2 AB をmin(A,B) * 2枚 買い、 残り * 1枚を買う
    ll zan = max(X,Y) - min(X,Y);
    if(X > Y)
    {
      //Aを多く買う
      iMin = min(iMin, min(X,Y) * 2* C + zan * A);
    }
    else
    {
      //Bを多く買う
      iMin = min(iMin, min(X,Y) * 2* C + zan * B);
    }
    
    //plan3 AB をmax(A,B) * 2枚買う
    iMin = min(iMin, max(X,Y) * 2 * C);

    cout << iMin << endl;

    return 0;

}