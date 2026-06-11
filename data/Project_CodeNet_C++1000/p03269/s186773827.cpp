#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
#define oset tree<int, null_type,greater<int>, rb_tree_tag,tree_order_statistics_node_update>


int main()
{
    int po[21];
    po[0] = 1;
    for(int i=1; i<21; i++){
        po[i] = po[i-1]<<1;
    }
    int l;
    cin >> l;

    int n = log2(l);
    n++;
    int m = n-1, lg;
    int ll = l;
    lg = log2(l);
    m += lg;
    l -= po[lg];

    while(l){
        lg = log2(l);
        m++;
        l -= po[lg];
    }

    cout << n << " " << m << "\n";
   // int ccc = 0;

    for(int i=1; i<n; i++){
        //printf("%d %d 0\n", i, i+1);
        cout << i << " " << i+1 << " 0\n";
        //ccc++;
    }

    l = ll;
    lg = log2(l);
    lg = po[lg];
    int i;

    for(i=0; po[i]<lg; i++){
        //printf("%d %d %d\n", i+1, i+2, po[i]);
        cout << i+1 << " " << i+2 << " " << po[i] << "\n";
        //ccc++;
    }

    l -= lg;
    i = po[i];
    while(l){
        lg = log2(l);
        //printf("%d %d %d\n", lg+1, n, i);
        cout << lg+1 << " " << n << " " << i << "\n";
        //ccc++;
        l -= po[lg];
        i += po[lg];
    }
    //cout << ccc << endl;

    return 0;
}
