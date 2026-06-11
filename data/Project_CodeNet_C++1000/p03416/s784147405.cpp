#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int result;
  result = 0;
  int a;
  int b;
  cin >> a;
  cin >> b;
    for (int i = a; i < b+1; i++)
    {
        if ((i%10==i/10000)&&((i/10)%10==(i/1000)%10))
        {
            result = result + 1;
        }
        
    }
    cout << result << endl;
}