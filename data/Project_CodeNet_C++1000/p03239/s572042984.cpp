
#include <bits/stdc++.h>
using namespace std;

int main(){
   
   int N; int T;
   cin >> N >> T;
   
   vector<int> c;
   vector<int> t;
   
   int aux1, aux2;
   for (int i=0; i < N; i++) {
   	cin >> aux1 >> aux2;
   	c.push_back(aux1); t.push_back(aux2);
   }
   
   vector<int> pos_candidatos;
   for (int i=0; i < N; i++) {
   	if (t[i] <= T) pos_candidatos.push_back(i);
   }
   
   int aux = -1;
   for (int i=0; i < pos_candidatos.size(); i++) {
 	 aux = c[pos_candidatos[0]];
 	 if (c[pos_candidatos[i]] < aux) aux = c[pos_candidatos[i]];
   }
   for (int i=pos_candidatos.size()-1; i >= 0; i--) {
 	 if (c[pos_candidatos[i]] < aux) aux = c[pos_candidatos[i]];
   }
   
   if (aux == -1) cout << "TLE";
   else cout << aux;

   return 0;
}