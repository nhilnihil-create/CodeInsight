#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int main(){
    int N,M,a,b,count,l,r,i;
    const int Mmax = 100000;
    P requirements[Mmax];

    cin >> N >> M;
    for(int i = 0;i < M;i++){
        cin >> a >> b;
        requirements[i] = P(a,b);
    }
    sort(requirements,requirements + M);

    l = requirements[0].first;
    r = requirements[0].second;
    i = 1;
    count = 0;
    while(i < M){
        if(r <= requirements[i].first){
            l = requirements[i].first;
            r = requirements[i].second;
            count++;
        }else if(requirements[i].second < r){
            l = requirements[i].first;
            r = requirements[i].second;
        }
        i++;
    }

    cout << ++count << endl;
}