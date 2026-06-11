#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << " ";

using namespace std;

vector<pair<long long, long long>> positions;
vector<long long> distances;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dc[4] = {'L', 'R', 'U', 'D'};
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	
	long long int min_total_length = 0;
	long long int x, y;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		positions.push_back(make_pair(x, y));
		distances.push_back(abs(x) + abs(y));
		min_total_length = max(min_total_length, abs(x) + abs(y));
	}
	//cerr << min_total_length << '\n';
	int parity = min_total_length % 2;
	for (auto d : distances){
		if (d % 2 != parity){
			cout << -1 << endl;
			return 0;
		}
	}
	
	/* //dumb solution
	cout << min_total_length << endl;
	for (int i = 0; i < min_total_length; i++){
		cout << 1;
		if (i != min_total_length - 1){
			cout << ' ';
		}
	}
	cout << endl;
	
	//find the shortest path, and then extend to the right, and back left as needed
	for (auto loc : positions){
		int x = loc.first; int y = loc.second;
		for (int i = 0; i < abs(x); ++i){
			if (x > 0) {
				cout << 'R';
			}
			else{
				cout << 'L';
			}
		}
		for (int i = 0; i < abs(y); ++i){
			if (y > 0) {
				cout << 'U';
			}
			else{
				cout << 'D';
			}
		}
		for (int i = 0; i < min_total_length - abs(x) - abs(y); i++){
			if (i % 2 == 0){
				cout << 'R';
			}
			else{
				cout << 'L';
			}
		}
		cout << '\n';
	} */
	//smart solution
	int size = 32 - parity;
	vector<long long> lengths;
	cout << size << endl;
	
	int start = 1;
	if (parity == 0){
		lengths.push_back(start);
		cout << start << ' ';
	}
	for (int i = 0; i < 31; i++){
		lengths.push_back(start);
		cout << start; if (i != 30) cout << ' ';
		start *= 2;
	}
	cout << endl;
	
	reverse(lengths.begin(), lengths.end());
	vector<char> directions;
	for (auto loc : positions){
		long long x = loc.first, y = loc.second;
		for (long long i : lengths){
			int remaining_length = i - parity;
			for (int j = 0; j < 4; j++){
				if (abs(x + dx[j] * i) + abs(y + dy[j] * i) <= remaining_length){
					x = x + dx[j] * i; y = y + dy[j] * i;
					directions.push_back(dc[j]);
					break;
				}					
			}
		}
		
		reverse(directions.begin(), directions.end());
		for (char c : directions){
			cout << c;
		}
		cout << endl;
		directions.clear();
	}
	
	
	return 0;
}
