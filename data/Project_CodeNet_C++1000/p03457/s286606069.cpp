    #include <bits/stdc++.h>
    using namespace std;
    main(){
      int n;cin >> n;
      int t[100010],x[100010],y[100010];
      t[0]=x[0]=y[0]=0;
      for(int i=0;i<n;i++) cin >> t[i+1] >> x[i+1] >> y[i+1];
      string ans="Yes";
      for(int i=0;i<n;i++){
        int dt = t[i+1]-t[i];
        int dist = abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
        if(dt>=dist){
          if(dt%2!=dist%2) ans="No";
        } else {
          ans = "No";
        }
      }
      cout << ans <<endl;
      return 0;
    }