#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int>prime;
    map<int,int>primeMap;
    prime.insert(2);
    prime.insert(3);
    prime.insert(5);
    prime.insert(7);
    for(int i=1;i<=n;i++){
      int tmp = i;
      for(int p:prime){
        while(tmp % p == 0){
          tmp /= p;
          primeMap[p]++;
        }
      }
      if(tmp > 1){
        primeMap[tmp]++;
        prime.insert(tmp);
      }
    }

    int ans = 0;
    for(int i:prime){
      if(primeMap[i] >= 74)ans++;
    }
    for(int i:prime){
      for(int j:prime){
        if(i!=j){
          if(primeMap[i] >= 24 && primeMap[j] >= 2)ans++;
        }
      }
    }

    for(int i:prime){
      for(int j:prime){
        if(i!=j){
          if(primeMap[i] >= 14 && primeMap[j] >= 4)ans++;
        }
      }
    }
    
    for(int i:prime){
      for(int j:prime){
        for(int k:prime){
          if(i<j && j!=k && k!=i){
            if(primeMap[i] >= 4 && primeMap[j] >= 4 && primeMap[k] >= 2)ans++;
          }
        }
      }
    }
    cout << ans << endl;
}
