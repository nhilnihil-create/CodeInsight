#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

typedef long long ll;

int main() {
   int N;
   cin >> N;
   string S;
   cin >> S;
   int Q;
   cin >> Q;
   int k[Q];
   for (int i = 0; i < Q; i++) {
      cin >> k[i];
   }

   ll SD[N + 1], SM[N + 1], SDM[N + 1];
   SD[0] = 0;
   SM[0] = 0;
   SDM[0] = 0;
   vector<int> Cid;
   for (int i = 0; i < N; i++) {
      if (S[i] == 'D') {
         SD[i + 1] = SD[i] + 1; 
      } else {
         SD[i + 1] = SD[i];
      }
      if (S[i] == 'M') {
         SM[i + 1] = SM[i] + 1;
         SDM[i + 1] = SDM[i] + SD[i];
      } else {
         SM[i + 1] = SM[i];
         SDM[i + 1] = SDM[i];
      }
      if (S[i] == 'C') {
         Cid.push_back(i);
      }
   }
   
   for (int ktmp = 0; ktmp < Q; ktmp++) {
      ll count = 0;
      for (int c = 0; c < Cid.size(); c++) {
         int minid = Cid[c] - k[ktmp];
         if (minid < 0) count += SDM[Cid[c] + 1];
         else {
            count += SDM[Cid[c] + 1];
            count -= SDM[minid + 1];
            count -= SD[minid + 1] * (SM[Cid[c] + 1] - SM[minid + 1]);
         }
      }
      cout << count << endl;
   }

   return 0;
}
