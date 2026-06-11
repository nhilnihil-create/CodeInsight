# include <iostream>
# include <map>
# include <algorithm>
using namespace std;

# define ll long long

int main(){
  
  ll untastyAntidote, tastyAntidote, tastyPoison;
  cin >> untastyAntidote >> tastyAntidote >> tastyPoison;
  
  ll ans = tastyAntidote + min(untastyAntidote + tastyAntidote + 1, tastyPoison);
  cout << ans << endl;
  return 0;
} 