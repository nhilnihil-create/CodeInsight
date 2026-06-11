#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

int main(void) {
    int n;
    Int sum = 0;
    string a,b,c;

    cin>>n;
    cin>>a>>b>>c;

    for(int i = 0;i < n;i++) {
        int ch = 0;
        if(a[i] == b[i])
            ch++;
        if(a[i] == c[i])
            ch++;
        if(b[i] == c[i])
            ch++;

        if(ch == 3)
            sum += 0;
        else if(ch == 1 || ch == 2)
            sum += 1;
        else
            sum += 2;
    }

    cout<<sum<<endl;

    return 0;
}
