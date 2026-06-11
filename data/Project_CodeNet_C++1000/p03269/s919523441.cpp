#include <bits/stdc++.h>
#define fr(i, n, m) for(int i = (n); i < (m); i ++)
#define pb push_back
#define pq priority_queue
#define st first
#define nd second
#define np next_permutation

using namespace std;
typedef long long ll;
ll const inf = 1e9;
ll const mod = 1e9 + 7;

int main()
{
    int l;
    cin >> l;
    l --;
    int k;
    fr(i, 1, 20){
        if((1 << i) - 1 <= l){
            k = i - 1;
        }
    }
    int rem = l - ((1 << (k + 1)) - 1);
    int n = 20;
    int m = 19 + k + 1;

    m += __builtin_popcount(rem);
    cout << n <<' '<<m<<endl;
    int curr = (1 << (k + 1));
    while(rem > 0){
        int x = rem&-rem;
        int v = log2(x);
        v ++;
        cout << v <<' '<<n<<' '<<curr << endl;
        curr += x;

        rem -= x;

    }
    fr(i, 1, n){
        cout << i <<' '<<i + 1 <<' '<<0<<endl;
    }
    fr(i, 1, k + 2){
        cout << i <<' '<<i + 1 <<' '<<(1 << (i - 1)) << endl;
    }



    return 0;
}
