#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S1, T;
    cin >> S1;
    cin >> T;
    string S;
    S = S1;
    bool hantei = true;
    vector<string> s;
    for (int i = 0; i < S.size() - T.size() + 1; i++)
    {
        S = S1;
        hantei = true;
       for (int j = 0; j < i; j++)
       {
           /* code */
          if (S[j] == '?')
          {
              /* code */
              S[j] = 'a';
          }
          
       }
       
       for (int k = 0; k < T.size(); k++)
       {
           /* code */
           if (S[i + k] == T[k])
           {
               /* code */
           }else if (S[i + k] != T[k] && S[i + k] != '?')
           {
               /* code */
                hantei = false;
                break;
           }
           
           else if (S[i + k] == '?')
           {
               /* code */
               S[i + k] = T[k]; 
           }
           
       }
       for (int l = T.size() + i; l < S.size(); l++)
       {
           if (S[l] == '?')
           {
               S[l] = 'a';
           }
           
       }
       
       if (hantei)
       {
          s.push_back(S);
       }
       
    }

    if(s.size() == 0) cout << "UNRESTORABLE" << endl;
    else { sort(s.begin(), s.end()); cout << s[0] << endl; }
    
    
    return 0;

}