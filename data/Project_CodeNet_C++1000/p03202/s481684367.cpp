#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int ub = n;
  int lb = 0;

  while(ub-lb>1){
    //    cout << "lb ub " << lb << " " << ub << endl;
    int mid = (ub+lb)/2;
    bool ok = true;
    map<int,int> cnt;
    rep1(i,n-1){
      if(a[i-1] < a[i]) continue;
      else{
	if(a[i-1]>=a[i]){
	  if(mid==1){
	    ok = false;
	    break;
	  }
	  if(a[i-1] >= a[i]){
	    if(a[i-1]>a[i]){
	      auto itr = cnt.upper_bound(a[i]);
	      if(itr!=cnt.end()){
		//		cout << "erase pos" << (*itr).first << endl;
		vector<int> er;
		for(;itr!=cnt.end();itr++){
		  er.pb((*itr).first);
		}
		for(int j=0;j<er.size();j++){
		  cnt.erase(er[j]);
		}
	      }
	    }
	    int cpos = a[i];
	    //	    cout << "pre cnt[cpos] cpos " << cnt[cpos] << " " << cpos << endl;
	    cnt[cpos]++;

	    while(cnt[cpos]==mid){
	      cnt.erase(cpos);
	      --cpos;
	      if(cpos==0){
		ok=false;
		break;
	      }
	      cnt[cpos]++;	    
	    }
	    //	    cout << "cnt[cpos] cpos " << cnt[cpos] << " " << cpos << endl;
		    
	  }
	}	
      }
      if(!ok) break;
    }

    if(ok) ub = mid;
    else lb = mid;    
  }
  cout << ub << endl;


  
  return 0;
    

}
