#include <iostream>
#include <cctype>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cmath>
#include <stack>
#include <algorithm>
#include <queue>
#include <iterator>
#include <limits>

using namespace std;

int main()
    {
          char str[16];
          int N,i,win=0;
          cin>>str;
          N=strlen(str);
          for(i = 0;i < N;i++)
          {
               if(str[i] == 'o')
               win++;
          }
          if(((15 - N) + win) >= 8)
          cout<<"YES";
          else
          cout<<"NO";
          //system("pause");
          return 0;
    }
