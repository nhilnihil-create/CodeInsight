#define REP(i, t, n)  for (int i = t; i < n; i++)
#define ALL(n)        (n).begin(),(n).end()
#include <limits.h>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <numeric>

using namespace std;

typedef bool               BOOL;
typedef short              WORD;
typedef unsigned short     U_WORD;
typedef long               DWORD;
typedef unsigned long      U_DWORD;
typedef long long          QWORD;
typedef unsigned long long U_QWORD;

#define N_MAX (100000)


typedef struct edge {
	DWORD	dwTo;
} EDGE;

vector <EDGE> vGraph[N_MAX + 1];
//vector <DWORD> vSortList;
queue  <DWORD> queNoInEdge;
DWORD  adwInEdgeNum[N_MAX + 1];
DWORD  adwNodeParent[N_MAX + 1];


void TopologicalSort()
{
	while (!queNoInEdge.empty()) {
		DWORD dwNode = queNoInEdge.front(); queNoInEdge.pop();
		//vSortList.push_back(dwNode);

		for (auto iter : vGraph[dwNode]) {
			adwInEdgeNum[iter.dwTo] -= 1;
			
			if (adwInEdgeNum[iter.dwTo] == 0) {
				queNoInEdge.push(iter.dwTo);
				adwNodeParent[iter.dwTo] = dwNode;
			}
		}
	}

}

void solve_main()
{
	DWORD N , M;
	cin >> N >> M;


	REP(i, 0, (N - 1 + M)) {
		DWORD dwFrom, dwTo;

		cin >> dwFrom >> dwTo;

		vGraph[dwFrom].push_back(EDGE{ dwTo });
		adwInEdgeNum[dwTo] += 1;
	}

	REP(i, 1, N + 1) {
		if (adwInEdgeNum[i] == 0) {
			queNoInEdge.push(i);
			adwNodeParent[i] = 0;
			break;			//最初に一つも流入量がないエッジは必ず根になる。他はすべて流入量が1以上のためここでbreak
		}
	}

	TopologicalSort();


	REP(i, 1, N + 1) {
		cout << adwNodeParent[i] << endl;
	}

}

int main()
{
#ifdef FOR_IDE
	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());
#endif

	solve_main();
	return 0;
}
