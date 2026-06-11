#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define sz size
#define forn(i, n) for (ll i = 0; i < (ll) (n); ++i)
#define forni(i, n) for (ll i = 2; i <= (ll) (n); ++i)
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using ll = long long;
const ll inf = 1e9+7; 

const double PI =  3.141592653589793;

int main(){
	IO;
	string s;
	ll ans=0;
	cin>>s;
	for(auto c :s){
		(c=='-')?ans--:ans++;
	}
	cout<<ans<<"\n";
	return 0;
}

// _   .-')                .-. .-')                 .-')                                               
//( '.( OO )_              \  ( OO )               ( OO ).                                             
// ,--.   ,--.).-'),-----. ,--. ,--.  .-'),-----. (_)---\_) ,--. ,--.     .-----.  ,-.-')  .-'),-----. 
// |   `.'   |( OO'  .-.  '|  .'   / ( OO'  .-.  '/    _ |  |  | |  |    '  .--./  |  |OO)( OO'  .-.  '
// |         |/   |  | |  ||      /, /   |  | |  |\  :` `.  |  | | .-')  |  |('-.  |  |  \/   |  | |  |
// |  |'.'|  |\_) |  |\|  ||     ' _)\_) |  |\|  | '..`''.) |  |_|( OO )/_) |OO  ) |  |(_/\_) |  |\|  |
// |  |   |  |  \ |  | |  ||  .   \    \ |  | |  |.-._)   \ |  | | `-' /||  |`-'| ,|  |_.'  \ |  | |  |
// |  |   |  |   `'  '-'  '|  |\   \    `'  '-'  '\       /('  '-'(_.-'(_'  '--'\(_|  |      `'  '-'  '
// """    """     """""""" """  """"      """""""  """""""  """"""""      """"""   """         """""""