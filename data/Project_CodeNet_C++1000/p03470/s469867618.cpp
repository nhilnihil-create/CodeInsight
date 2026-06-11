#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(){

int i,N,count=0,step;

cin >> N;
vector<int> d(N);

step=N;

for(i=0;i<N;i++){
cin >> d[i];
}

sort(d.begin(),d.end());

for(i=N-1;i>0;i--){
  if(d[i]==d[i-1]){
    count++;
  }

}

cout << step-count << endl;
}
