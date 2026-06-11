#include<iostream>
#include<algorithm>
#include<queue>
int graph[50][50];
using namespace std;
int n, m;
int bfs();
int main() {

	//C
	cin >> n >> m;

	//queue<int> graph[50];
	//int graph[50][50];
	int i,j,a,b;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
	}
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}
	//cout << graph[1][6];
	int counter = 0;

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
	//i = 1; j = 6;
			if (graph[i][j] == 1) {
				graph[i][j] = 0;
				graph[j][i] = 0;

				if (bfs() == 0) {
					counter++;
					//cout << i << ' ' << j << endl;
				}

				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
	}
	cout << counter << endl;
	return 0;



	//D
	/*
	long long int x[50], xs[50], y[50], ys[50];
	int n, k;
	cin >> n >> k;
	int i1,i2,j1,j2,i,l;
	for (i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		xs[i] = x[i]; ys[i] = y[i];
	}
	sort(xs, xs + n);
	sort(ys, ys + n);
	int counter;
	long long int rectangle = 4000000000000000000;
	for (i1 = 0; i1 < n-1; i1++) {
		for (j1 = i1 + 1; j1 < n; j1++) {
			for (i2 = 0; i2 < n - 1; i2++) {
				for (j2 = i2 + 1; j2 < n; j2++) {
					if ((xs[j1] - xs[i1]) * (ys[j2] - ys[i2]) < rectangle) {


						counter = 0;
						for (i = 0; i < n; i++) {
							if ((x[i] >= xs[i1]) && (x[i] <= xs[j1]) && (y[i] >= ys[i2]) && (y[i] <= ys[j2])) {
								counter++;
							}
						}
						if (counter >= k) {
							rectangle = (xs[j1] - xs[i1]) * (ys[j2] - ys[i2]);
						}
					}
				}
			}
		}
	}
	cout << rectangle << endl;
	return 0;
	*/
}
int bfs() {
	int i, j;
	int edge[50];
	for (i = 0; i < n; i++) {
		edge[i] = 0;
	}
	queue<int> q;
	q.push(0);
	edge[0] = 1;
	int x;
	while (q.size()>0) {
		//cout << 'a';
		x = q.front(); q.pop();
		for (i = 0; i < n; i++) {
			//cout << 'a';
			//cout << x << ' ' << i << endl;
			if (i != x) {
				if (graph[x][i] == 1) {
					if (edge[i] == 0) {
						//cout << x << ' ' << i << endl;
						edge[i] = 1;
						q.push(i);
						//cout << i << endl;
					}
				}
			}
		}

	}
	for (i = 0; i < n; i++) {
		if (edge[i] == 0) {
			//cout << i << endl;
			return 0;
		}
	}
	return 1;
	
}