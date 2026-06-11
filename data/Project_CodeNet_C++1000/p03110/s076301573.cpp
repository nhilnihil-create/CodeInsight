
#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;



int main() {
  int n;
  cin >> n;
  double sum=0;
  rep(i,n) {
        double m;
        string s;
        cin >> m >> s;
        if (s == "JPY") {
            sum += m;
        } else {
            sum += m * 380000.0;
        }
    }
  printf("%.10f\n",sum);
}