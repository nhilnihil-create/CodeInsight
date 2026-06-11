 #include <bits/stdc++.h>
    using namespace std;
	int main(){
      int A,B;
      cin >> A >> B;
      int answer = 0;
      
      for(int i = A; i < B+1; i++){
        string j = to_string(i);
        string p,q,r,s,t;
        p = j[0];
        q = j[1];
        r = j[2];
        s = j[3];
        t = j[4];
        if (p == t && q ==s) answer++;
        else continue;
      }
      cout << answer << endl;
    }
