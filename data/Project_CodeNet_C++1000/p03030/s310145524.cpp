#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int h,w,n,i=0,j,p;
    string s;
    pair<pair<string,int>,int> a[1000];
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> s >> p;
        a[i]=make_pair(make_pair(s,-p),i+1);
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        cout << a[i].second << endl;
    }
    return 0;
}
