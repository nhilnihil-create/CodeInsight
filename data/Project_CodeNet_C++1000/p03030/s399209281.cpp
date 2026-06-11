#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char c[11];
    pair<pair<string,int>,int> p[101];

    for (int i=0;i<n;i++){
        int temp;
        scanf("%s%d",c,&temp);
        p[i]=make_pair(make_pair(c,-temp),i+1);
    }
    sort(p,p+n);
    for (int j=0;j<n;j++)printf("%d\n",p[j].second);
}
