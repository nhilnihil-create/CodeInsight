#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define fastio                        \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL);
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

int main()
{
    fastio;
    int n;
    cin>>n;
    int *a = new int[n];
    for (int i =0;i<n;i++) {
        cin>>a[i];

    }
    int count = 0;
    while (true) {
        bool even = false;
        for (int i=0;i<n;i++) {
            if (!(a[i]&1)) {
                even = true; count++; 
                a[i]/=2;break;
            }
        }
        if(even == false){
            cout<<count<<endl;
            break;
        }
    }

    return 0;
}