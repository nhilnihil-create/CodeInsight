#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;

int main()
{
    int N;  cin >> N;
    vector<int> c(N), s(N), f(N);
    for(int i=0; i<N-1; i++)  cin >> c[i] >> s[i] >> f[i];
    for(int i=0; i<N; i++){
        int t = 0;
        for(int j=i; j<N-1; j++){
            if(j == i)  t += c[j] + s[j];
            else{
                if(t <= s[j])    t = c[j] + s[j];
                else if(t%f[j] == 0)   t += c[j];
                else    t += c[j] + f[j] - t%f[j];
            }
        }
        cout << t << endl;
    }
    return 0;
}